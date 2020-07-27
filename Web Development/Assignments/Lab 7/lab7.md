# Lab 7

## Problem 1

You will create JavaScript prevalidation for the form listed below. Following are the
suggestions of Instructions and Test procedure. (The source files are on the Blackboard.)

### Instructions

1. Link to an external JavaScript file in the head of the page so that you can write
code in its own file
2. Define a CSS style to use when highlighting a blank field
3. Set up a listener on the form’s submit event so that the code prevents submission
of the form (preventDefault()) if either the title or description field is left
blank or the accept license box is not checked
4. Enhance the JavaScript so that blank fields trigger a change in the appearance of
the form

### Analysis

- The main issue I ran into while trying to solve this problem was selecting the form elements properly. I was ultimately able to do this with Javascript's querySelector function which lets you use css selector syntax on elements. This made it simple to select the correct input tag by specifying the type.
- Additionally I had to do some research on the specifics for checking whether or not a text field/area or check box was empty/unchecked. This was a quick problem, though.
- I was also initially unsure how to submit the form if it was valid. I originally called preventDefault on click and then tried to submit after that, but only calling preventDefault if it was invalid worked better.


### Source Code

```css
.highlighted {
   background-color: #FF3333 !important;
   box-shadow: 0 0 10px #FF3333;
}
```

```javascript
var submitButton = document.querySelector('input[type="submit"]');
var title = document.querySelector('input[name="title"]');
var description = document.querySelector('textarea[name="description"]');
var acceptLicense = document.querySelector('input[name="accept"]');

submitButton.addEventListener('click', function(event) {
    if (checkElements()) {
        console.log('true');
    }
    else {
        event.preventDefault();
        highlightEmpty();
        console.log('false');
    }
});

function checkElements() {
    console.log("title.value: " + title.value);
    console.log("description.value: " + description.value);
    console.log("acceptLicense: " + acceptLicense.checked);

    return !(title.value == "" || description.value == "" || !acceptLicense.checked);
}

function highlightEmpty() {
    if (title.value == "") {
        title.classList.add('highlighted');
        title.parentElement.classList.add('highlighted');
    }
    if (description.value == "") {
        description.classList.add('highlighted');
        description.parentElement.classList.add('highlighted');
    }
    if (!acceptLicense.checked) {
        acceptLicense.classList.add('highlighted');
        acceptLicense.parentElement.classList.add('highlighted');
    }
}
```

### Screenshots

![highlighted text](https://i.ibb.co/9sGyN4J/image.png)

![highlight check box](https://i.ibb.co/Y3VRP6g/image.png)
