<?php

/**
 * @file
 * Admin menu page callbacks of the module.
 */

/**
 * Module-wide settings form.
 */
function term_merge_admin_settings_form($form, &$form_state) {
  $config = config('term_merge.settings');
  $form['#config'] = 'term_merge.settings';
  $form['select_limit'] = array(
    '#type' => 'number',
    '#title' => t('Threshold for "Select" widget'),
    '#description' => t('Specify a threshold (number of terms) for which the "select" widget should be the default when specifying the trunk term.'),
    '#default_value' => $config->get('select_limit'),
    '#required' => TRUE,
    '#min' => 0,
  );

  if (module_exists('redirect')) {
    $form['default_redirect'] = array(
      '#type' => 'select',
      '#title' => t('Default redirect'),
      '#description' => t('Default redirect action to take when merging terms.'),
      '#default_value' => $config->get('default_redirect') ?? TERM_MERGE_NO_REDIRECT,
      '#options' => term_merge_redirect_options(),
      '#required' => TRUE,
    );
  }

  return system_settings_form($form);
}
