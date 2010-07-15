<?php
// $Id$

/**
 * @file
 *
 *
 *Menu callbacks for Workflow_og.
 */ 

/**
 * A simple page callback.
 *
 * Page callbacks are required to return the entire page. The content
 * is then usually output via a call to theme('page'), where the theme system
 * will then surround the content in the appropriate blocks, navigation, and
 * styling.
 *
 * If you do not want to use the theme system (for example for outputting an
 * image or XML), you should print the content yourself and not return anything.
 */
/**
 * This is Example 2, a basic form with a submit button.
 * @see http://drupal.org/node/717726
 */
function workflow_og_promote(&$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A simple form with a submit button'),
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
  );
  
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
  return $form;
}