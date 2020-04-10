# XML vs JSON

## XML

XML stands for eXtensible Markup Language. It is designed to carry data. Here, the tags are not predefined, and the user defines tags. It is designed to be self-descriptive and provide information in a concise, namespace like format.

```
<note>
    <to>Tove</to>
    <from>Jani</from>
    <heading>Reminder</heading>
    <body>Don't forget me this weekend!</body>
</note>
```

Some features of XML are
1. Well formed
   1. Each element must have a closing tag
   2. Tags are case sensitive
   3. Proper nesting
   4. Attribute values must be quoted
2. Validity
   1. An XML document that has an associated document type declaration and complies to its constraints
      1. Document Type Definition (DTD)
      2. XML Schema
3. Processing files
   1. SAX API or DOM API or others
4. Transformation Engines and Filters
   1. XSL-FO is a declarative XML based layout language
   2. XSLT is a declarative XML based document transformation language. A XSLT processor can use a XSLT stylesheet to convert the data tree into another tree for serialisation.
   
XML gives the advantages of
1. Basic syntax
2. Data available to all kinds of reading machines
3. Gateway for communication between applications
4. Supports unicode
5. Can represent standard data structures
6. Self documenting format describes structure and field names as well as specific values
7. Based on international standards

Its disadvantages are
1. Difficult to understand
2. Syntax is redundant
3. Not too efficient
4. Very verbose
5. Heirarchical model limited
6. Overlapping is not modeled well
7. Namespaces are problematic to use

## RSS

RSS stands for Really Simple Syndication and is a family of feed formats to publish frequent data. These are read by feed aggregators or readers, which is in XML format.

Advantages
1. All news at one place
2. Freedom from email overload
3. Easier publishing
4. Simpler data writing process
5. Relevance and timely

RSS is based on DTDs and starts with `<rss version = "<version>">`.

## JSON

JSON (Java Script Object Notation) is a lightweight data-interchange format. It is language dependent and is a collection of key-value pairs. It can be converted into an object using eval(). 

## JSON vs XML

1. JSON is smaller
2. JSON needs less time to parse
3. JSON is faster in AJAX
4. XML uses XHR
5. JSON can use JSONRequest
6. Speed: fetching is the same, parsing is not
7. JSON vulnerable to code injection
8. JSON is thinner
9. JSON is native
10. JSON can do cross domain calls
11. JSON is easier to encode
12. JSON better on client side, XML on server side