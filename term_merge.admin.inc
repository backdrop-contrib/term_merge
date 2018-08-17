<?php

/**
 * @file
 * Admin menu page callbacks of the module.
 */

/**
 * Module-wide settings form.
 */
function term_merge_admin_settings_form($form, &$form_state) {
  $form['term_merge_select_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Threshold for "Select" widget'),
    '#description' => t('Specify a threshold (number of terms) for which the "select" widget should be the default when specifying the trunk term.'),
    '#default_value' => variable_get('term_merge_select_limit', 200),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  if (module_exists('redirect')) {
    $form['term_merge_default_redirect'] = array(
      '#type' => 'select',
      '#title' => t('Default redirect'),
      '#description' => t('Default redirect action to take when merging terms.'),
      '#default_value' => variable_get('term_merge_default_redirect', TERM_MERGE_NO_REDIRECT),
      '#options' => term_merge_redirect_options(),
      '#required' => TRUE,
    );
  }

  return system_settings_form($form);
}
