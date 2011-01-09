<?php
// $Id$

/**
 * @file
 *   administration page callbacks for faccess module
 */

/**
 * Form builder. admin/settings/faccess
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function faccess_admin_settings() { 
  $features = features_get_features();
  // Organize feature sets.
  foreach($features as $feature) {
    $package_title = ($feature->info['package']) ? $feature->info['package'] : 'Other';
    $package = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $package_title));
    // Everything should be organized by package or "feature set"
    $form[$package] = array(
      '#title' => t($package_title),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE, 
    );
  }
  // Organize features. 
  foreach($features as $feature) {
    $title = $feature->info['name'];  
    // Variables to be stored in variable table: $element, $action, $url.
    $element = "faccess_". $feature->name;
    $action =  $element ."_action";
    $url = $element ."_url";
    // collapsible groups
    $package_title = ($feature->info['package']) ? $feature->info['package'] : 'Other';
    $package = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $package_title));
    $group = "group_". $feature->name;
    // form
    $form[$package][$group] = array(
      '#title' => t($title),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE, 
    );
    $form[$package][$group][$element] = array(
      '#type' => 'checkbox', // Use checkbox instead of checkboxes so each feature has own
                             // variable in variable table. Easier to manipulate with 
                             // x module and strong arm this way.
      '#title' => t($title),
      '#default_value' => variable_get($element, FALSE),
      '#description' => t('Checked features will be hidden '
        .'from users on !features.', 
        array('!features' => l('admin/build/features', 'admin/build/features'))),
    ); 
    $form[$package][$group][$action] = array(
      '#type' => 'textfield',
      '#title' => t('Action (e.g. "Buy This" or "Contact Administrator")'),
      '#default_value' => variable_get($action, FALSE),
      '#description' => t('This text will replace the "Recreate" link in the admin column '
                         .'on admin/build/features'),
    ); 
    $form[$package][$group][$url] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#default_value' => variable_get($url, FALSE),
      '#description' => t('This is the URL your action link will send the user to. '
                         .'E.g. http://example.com/store'),
    ); 
  }

  return system_settings_form($form);
} 
