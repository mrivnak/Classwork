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

