<?php
// $Id$

/**
 * @file
 *
 *
 *Menu callbacks for Workflow_og.
 */ 

function workflow_og_og_audience(&$form, &$form_state) {
  global $user;
  // Determine the selected groups if it is stored in the form_state.
  if (!empty($form_state['og_gids'][0]) && empty($form_state['og_groups'])) {
    $gids = explode(',', $form_state['og_gids'][0]);
  }

  $node = $form['#node'];
  $required = variable_get('og_audience_required', 0) && !user_access('administer nodes');
  $is_optgroup = FALSE;

  // Determine the list of groups that are shown.
  // Start by collecting all groups that the user is a member of.
  $subs = og_get_subscriptions($user->uid);
  $options = array();
  foreach ($subs as $key => $val) {
    $options[$key] = $val['title'];
  }
  if (user_access('administer nodes')) {
    // Node admins see all of groups.
    $all = og_all_groups_options();
    $other = array_diff_assoc($all, $options);
    // Use an optgroup if admin is not a member of all groups.
    if ($other) {
      $options = array(
        t('My groups') => $options,
        t('Other groups') => $other,
      );
      $is_optgroup = TRUE;
    }
    else {
      $options = $all;
    }
  }
  else {
    // Classify those groups which the node already has but the author does not.
    if (!isset($node->og_groups_both)) {
      $node->og_groups_both = array();
    }
    $current_groups = og_node_groups_distinguish($node->og_groups_both);
    // Put inaccessible groups in the $form so that they can persist. See og_presave_group() and og_access_alter_nongroup_form() in og_access.module
    $form['og_invisible']['og_groups_inaccessible'] = array('#type' => 'value', '#value' => $current_groups['inaccessible']);

    // Add the accessible groups that they node already belongs to.
    if ($current_groups['accessible']) {
      // Use an optgroup to distinguish between my memberships and additional groups in the Audience select.
      // There is code below which assumes that $options does not have optgroups but that code is within a $simple check
      // So we are OK as long as $simple does not apply to node edits.
      // NOTE: If you form_alter the audience element, beware that it can sometimes be an optgroup.
      foreach ($current_groups['accessible'] as $key => $val) {
        $other[$key] = $val['title'];
      }

      $options = array(
        t('My groups') => $options,
        t('Other groups') => $other,
      );
      $is_optgroup = TRUE;
    }
  }



