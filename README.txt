Feature Access
---------------

This module lets you prevent users from enabling features selected 
on the admin/settings/faccess page.

The settings page prompts you to do three things: 

  1. Check features which should have restricted access.
     This will prevent the user from being able to check
     the checkbox on admin/build/features.

  2. Enter "action" text. This is the text that will go in 
     the Action column on the admin/build/features page.
     The action link says "Recreate" by default. This module
     lets you change it to something like, "Buy this module".

  3. Enter a URL for the action link. E.g. You could send the user
     to http://example.com/store to purchase the feature.

This module creates variables in variable table like this: 
faccess_mymodule, value = TRUE/FALSE. 
faccess_mymodule_action, value = action link text
faccess_mymodule_url, value = url for action link

Also see include Package Access module.


maintainter
--------------
Bryan Hirsch, bryan AT bryanhirsch DOT com
