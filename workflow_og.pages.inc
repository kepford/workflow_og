<?php
// $Id$

/**
 * @file
 *
 *
 *Menu callbacks for Workflow_og.
 */ 

function workflow_og_promote(&$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Promote application to appropriate group'),
  );

 dprint_r($_SESSION);

  $form['promote_audience'] = array(
  '#type' => 'radios', 
  '#title' => t('Assign to Division'), 
  '#default_value' => t('FCC Applied Technology Division', 1), 
  '#options' => array(t('FCC Applied Technology Division'), t('FCC Fine, Performing and Communication Arts Division'), t('FCC Health Sciences Division'), t('FCC Humanities Division'), t('FCC Math, Science and Engineering Division')),
);


  // Adds a simple submit button that refreshes the form and clears its contents -- this is the default behavior for forms.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  
   $form['clear'] = array(
    '#type' => 'submit',
    '#value' => 'Cancel',
    '#validate' => array('workflow_og_clear'),
  );
  return $form;
}

/**
 * 
 * Setting the $form_state['rebuild'] value to TRUE says that we're going to
 * rebuild the form.  We also clear the existing values.
 * 
 */
function workflow_og_clear($form, &$form_state) {
    $form_state['rebuild'] = TRUE;
    unset($form_state['values']);
}