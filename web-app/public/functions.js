const pizza = document.getElementById('pizza');
const hamburger = document.getElementById('hamburger');
const goulash = document.getElementById('goulash');
const sarma = document.getElementById('sarma');
const wings = document.getElementById('wings');
const vegetables = document.getElementById('vegetables');
const output = document.getElementById('output');
const error = document.getElementById('error');

const buttons = document.querySelectorAll('button');

pizza.addEventListener('click', function() {
    output.textContent = 'You have selected pizza!';
});

hamburger.addEventListener('click', function() {
    output.textContent = 'You have selected hamburger!';
});

goulash.addEventListener('click', function() {
    output.textContent = 'You have selected goulash!';
});

sarma.addEventListener('click', function() {
    output.textContent = 'You have selected sarma!';
});

wings.addEventListener('click', function() {
    output.textContent = 'You have selected wings!';
});

vegetables.addEventListener('click', function() {
    output.textContent = 'You have selected vegetables!';
});

localStorage.setItem('outputText', output.textContent);

const resetButton = document.getElementById('resetButton');
resetButton.addEventListener('click', function() {
    output.textContent = '';
    error.textContent = '';
});

const acceptButton = document.getElementById('acceptButton');
acceptButton.addEventListener('click', function() {

    if (output.textContent === '') {
        error.textContent = 'You have not selected your meal.';
    }
    else{
        error.textContent = '';
        window.location.href = `./status.html`;
    }
});