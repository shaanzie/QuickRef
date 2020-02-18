# AJAX Patterns

## Predictive Fetch

In this, the Ajax application guesses what the user is going to do next and retrieves the appropriate data. Determining these user actions is very hard to do. In some cases, however, this can be easy, such as small websites where there exist only 3 pages, so you load all 3 of them, before the user navigates to any other page in the website.

The technique is to load the other pages into a div, and when the URL is shifted, the divs can change their display sets.

## Submission Throttling

In submission throttling, data is buffered to be sent to the server and the data is sent at predetermined times. It basically waits a certain amount of time and then sends all the characters in the box. 

## Periodic Refresh

This describes the process of checking for new server information at specific intervals, also called polling.

## Multi-Stage Download

In this, basic functionality is loaded into a page initially. Upon completion, the page begins to download other contents on the page. Sometimes, browsers don't have AJAX. In this, graceful degradation occurs where the simple browsers will not get the same benefits as the browsers that support the technology.