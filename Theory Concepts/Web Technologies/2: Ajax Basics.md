# AJAX basics

Ajax is an approach to web interaction that transmits a small amount of information between a client and a server to give a responsive experience.

It uses an AJAX engine that handles communication through JS functions with scheduling and execution, asynchronously.

The main principles behind AJAX are
1. Minimal traffic
2. Consistency
3. Standard
4. No distractions
5. Accessibility
6. Usability

## Hidden Frames

Hidden frames create framesets used for client-server communication. This frame is hidden from the webpage. It follows a 4 step pattern, when the user makes a request.
1. A JS function call is made to the hidden frame
2. A request is sent to the server.
3. A response is received from the server
4. Data can be rendered by an event handler

### Hidden Frames GET

Frames are defined as
```
<frameset>
    <frame src = "a.html" />
    <frame src = "b.html" />
</frameset>
```

Upon a request, the data sent to the server gets a response in the frame called to render the specific webpage `b.html`. This allows the communication to happen asynchronously.

### Hidden Frames POST

For post, a form is made with the target set to the hiddenframe. When the user hits submit, the data is rendered onto the frame, due to the target attribute, and then can be rendered onto anywhere on the webpage.

## Hidden iFrames

The next generation of hidden frames was hidden iframes, which can be placed inside of a non-frameset HTML page, allowing any part of the page to become a frame. 

### Hidden iFrames POST

The approach is to load a page that contains a form into the hidden frame, populate it with data, and submit it. When the visible form hits submit, cancel the submission and forward the information into the hidden frame. 

## Advantages and Disadvantages of Hidden Frames

Advantages
1. Can maintain brower history - Moves in the history of the frames

Disadvantages
1. Very little info about behind the scenes logic, no failure control

## Image based AJAX

Image based AJAX is sending images for success and failure. This is done to counter latency issues in huge amounts of data being sent back for essentially binary operations. 

Upon success, a pixel is sent back from the backend to indicate that the response is on the way.

## Script Tags

`<script>` tags can also be used with the src attribute to handle asynchronous requests. This is done by appending the url of the src property with the data to get as a request.

When the data is a post, the backend can just check for a script being sent and give the appropriate callback in a format that can be echoed back by the backend.

```
var payload = "rating=" + encodeValue(rating);
payload += "&transport=script";
payload += "&response=script";

<?php

    if($response == "script")
    {
        $message .= "$callback('$rating', '$votes', '$average');"
        print($message);
        exit;
    }
?>
```

## XMLHttp Requests

The XMLHttp object was created to enable initiating HTTP requests from anywhere in the application. These requests were intended to return XML.

After creating a new XMLHttp object, the first step is to call open(), which initialises the object. The parameters are
1. Request Type
2. URL
3. Async : Whether request must be async

The readyState determines the state in which the request is
1. 0 - Unitialised
2. 1 - loading
3. 2 - loaded
4. 3 - interactive
5. 4 - Complete

The send() method is the one that actually sends the request. The response can be obtained through responseText or responseXML. 

### XMLHttp GET and POST

In contrast to the hidden frame/iframe example, no JS code is required out of the main page. Here, it is much easier to debug due to the readystatechange property.

## Advantages and Disadvantages of AJAX

The advantages are that the code is cleaner and debugging is better. The main disadvantage is browser history cannot be maintained.