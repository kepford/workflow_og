<?php
// $Id$

/**
 * @file
 *
 *
 *Menu callbacks for Workflow_og.
 */ 

function workflow_og_promote(&$form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Promote application to appropriate group'),
  );


  $form['promote_audience'] = array(
  '#type' => 'radios', 
  '#title' => t('Assign to Division'), 
  '#options' => array(t('FCC Applied Technology Division'), t('FCC Fine, Performing and Communication Arts Division'), t('FCC Health Sciences Division'), t('FCC Humanities Division'), t('FCC Math, Science and Engineering Division')),
);


  // Adds a simple submit button that refreshes the form and clears its contents -- this is the default behavior for forms.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  
  // Adds a new button to clear the form. The #validate property
  // directs the form to use a validation handler function specific
  // to this button instead of using the default handler.
/*
  $form['clear'] = array(
    '#type' => 'submit',
    '#value' => 'Reset form',
    '#validate' => array('workflow_og_promote_clear'),
  );
*/

  return $form;
}

/**
 * Validation function for the reset button.
 *
 * Setting the $form_state['rebuild'] value to TRUE says that we're going to
 * rebuild the form.  We also clear the existing values, although values
 * aren't used in the form builder in this example.
 */
/*
function workflow_og_promote_clear($form, &$form_state) {
    $form_state['rebuild'] = TRUE;
    unset($form_state['values']);
}
*/