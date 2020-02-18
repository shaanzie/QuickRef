# CORS

CORS stands for Cross-Origin-Resource-Sharing. It is a mechanism that uses additional HTTP headers to tell browsers to give a web application running at one origin, access to selected resources at another origin. This can be modified by telling the browser which origins are permitted to read that information. 

Specification mandates that browsers preflight the request, for requests apart from GET and POST as they can affect the server side. These solicit methods from the server with HTTP OPTIONS and then send the request if the OPTIONS request is approved. The Access-Control-Allow-Origin header allows CORS to be circumvented for that origin. Similarly Allow-Methods and Allow-Headers are used for the same reason.