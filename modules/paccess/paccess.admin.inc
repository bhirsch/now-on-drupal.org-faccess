<?php
// $Id$

/**
 * @file
 *   administration page callbacks for paccess module
 */

/**
 * Form builder. admin/settings/paccess
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function paccess_admin_settings() { 
  $features = features_get_features();
  // Organize feature sets.
  foreach($features as $feature) {
    $package_title = ($feature->info['package']) ? $feature->info['package'] : 'Other';
    $package = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $package_title));
    // Variable to be stored in variable table: $element.
    $element = 'paccess_'. $package;
    $form[$element] = array(
      '#type' => 'checkbox', // Use checkbox instead of checkboxes so each feature has own
                             // variable in variable table. Easier to manipulate with 
                             // x module and strong arm this way.
      '#title' => t($package_title),
      '#default_value' => variable_get($element, FALSE),
      '#description' => t('Checked feature sets will be hidden from users on !features.', 
               array('!features' => l('admin/build/features', 'admin/build/features'))),
    ); 
  }

  return system_settings_form($form);
} 
