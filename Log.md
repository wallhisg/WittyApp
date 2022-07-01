# 22-06-27 Install CssLinter
Terminal:
	sudo apt install npm
	sudo apt install nodejs
	npm install -g csslint
Sublime Text package:
	SublimeLinter
# 22-06-26
Enable Livereload
ref: https://github.com/livereload/livereload-js?fbclid=IwAR2yMjH9tVlTHX3rqZINPT4HV-A63p6L5t1HT6spMWm6aH3r1NK_rQukQR4
- Install Livereload in Sublime Text
- Add lines
    this->instance()->doJavaScript("document.write('<script src=\"http://' \
    					+ location.host.split(':')[0]	\
    					+ ':35729/livereload.js\"></'+'script>')");
- Install Livereload extension, Setting in chrome
	1: go to chrome://flags/#block-insecure-private-network-requests
	2: set Block insecure private network requests to Disabled

# 22-06-21
Layouting for mobile and desktop
In your wt_config.xml set this option from FALSE to TRUE:
<progressive-bootstrap>true</progressive-bootstrap>

# 22-06-19
- write function ChangeName on both Server and ServerWidget

# 22-06-14
- Khoi tao class WebEvent	=>	processWebEvent
- Khoi tao class DevEvent	=>	processDevicecEvent

