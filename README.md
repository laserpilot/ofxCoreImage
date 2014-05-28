ofxCoreImage
============

This gives you several classes to easily use OSX's Core image filters within openFrameworks 0.8.0+

Everything is based off the original example from this super helpful post: http://bathatmedia.blogspot.com/2013/08/using-coreimage-filters-in.html


CURRENTLY A WORK IN PROGRESS - Beware using in real productions yet - there are some memory leaks with the BoxBlur and ZoomBlur filters that are inherent in OSX. I am also slowly implementing individual filters as I work through them. Most filters run at 60fps right now, except for some of the blurs and edge filters.

This addon lets you really easily implement Core Image Filters into OF programs on OSX only. The document "CIFilters.txt" gives you a list/attributes/description of all possible built in filters. You can also make your own classes for third party filters like those from FX Factory.

I would use my example file as a starter template for your own project for now...

If starting a project from scratch you will need to add QuartzCore to your project in build phases!

This is also not currently working inside the default GLFW window, so you will need to build using the older GLUT windows - there will be a fix for this soon, but it will involve using seperate GL contexts so it may impact speed.

Here is a sample video of some of the filters in action: https://vimeo.com/96629231

Also check out: https://github.com/Ahbee/ofxCoreImageFilters for an alternative and more automatic implementation of using the filters
