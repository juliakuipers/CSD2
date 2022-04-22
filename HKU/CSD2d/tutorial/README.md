for this to run you need to have a path from the sketch thats being used to the openFrameWorks base folder

When running this code, sometimes you can get the unexpected "resource fork, Finder information, or similar detritus not allowed" error message.

This refers to additional files and/or information stored in your .app bundle.
Code signing no longer allows any file in an app bundle to have an extended attribute containing a resource fork or Finder info.

To see which files are causing this error, run this command in Terminal:

You can list the extra's like so:

$ xattr -lr <path_to_app_bundle>
and you can clean them up like so:

$ xattr -cr <path_to_app_bundle>
According to Apple:
Note that browsing files within a bundle with Finder's Show Package Contents command can cause Finder info to be added to those files.

source: https://www.tweaking4all.com/forum/delphi-lazarus-free-pascal/macos-resource-fork-finder-information-or-similar-detritus-not-allowed/
