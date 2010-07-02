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
function promote_workflow_og() {
  return '<p>' . t('Here is where our form will live.') . ' </p>';
}
