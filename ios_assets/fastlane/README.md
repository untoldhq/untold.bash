fastlane documentation
================
# Installation
```
sudo gem install fastlane
```
# Available Actions
## iOS
### ios test
```
fastlane ios test
```
Runs all the tests
### ios prebuild
```
fastlane ios prebuild
```
Runs various pre-build tasks
### ios tf
```
fastlane ios tf
```
Submit a new Beta Build to Apple TestFlight

This will also make sure the profile is up to date
### ios changelog
```
fastlane ios changelog
```
Add a new note to the changelog

Usage: fastlane changelog log:"My changelog notes"
### ios ci_testflight
```
fastlane ios ci_testflight
```
Exactly the same as the tf lane, but runs the setup_jenkins action beforehand
### ios nightly
```
fastlane ios nightly
```
Builds a nightly build and uploads it to Hockey
### ios release
```
fastlane ios release
```
Release a build a stable build
### ios register
```
fastlane ios register
```
Register the given device in the developer portal

Syntax: fastlane register device:"device UDID" name:"Device Name"
### ios bump
```
fastlane ios bump
```
Bump the build number
### ios commitbump
```
fastlane ios commitbump
```
Commit the version bump and push to master
### ios newsprint
```
fastlane ios newsprint
```
Start up a new sprint
### ios certificates
```
fastlane ios certificates
```
Pull provisioning profiles & certificates
### ios force_certificates
```
fastlane ios force_certificates
```
Generate or pull provisioning profiles & certificates
### ios archive
```
fastlane ios archive
```
Archive
### ios pods
```
fastlane ios pods
```
Install cocoapods via bundler
### ios pr
```
fastlane ios pr
```
Evaluates a github pull request
### ios build_enterprise
```
fastlane ios build_enterprise
```
build Nokia enterprise ipa
### ios upload_enterprise
```
fastlane ios upload_enterprise
```
upload Nokia enterprise ipa to hockey
### ios build_version_file
```
fastlane ios build_version_file
```
build version file from ipa

----

This README.md is auto-generated and will be re-generated every time [fastlane](https://fastlane.tools) is run.
More information about fastlane can be found on [https://fastlane.tools](https://fastlane.tools).
The documentation of fastlane can be found on [GitHub](https://github.com/fastlane/fastlane/tree/master/fastlane).
