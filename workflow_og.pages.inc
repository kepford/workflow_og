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
function workflow_og_promote_tab() {
  
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form with nothing but a textfield'),
  );
  // This is the first form element. It's a textfield with a label, "Name"
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
  );
  return $form;

}
