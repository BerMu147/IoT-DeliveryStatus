const output = document.getElementById('output') || "";

const ledIds = [1, 2, 3]

function ledOn(led_id) {
    if (!ledIds.includes(led_id)) return false

    let ledsToBeTurnedOff = ledIds.filter(x => x !== led_id);
    ledOff(ledsToBeTurnedOff);

    database.ref(`LED/led_${led_id}`).set({
        turnedOn: true
    });
}

function ledOff(led_ids = ledIds) {
    led_ids.forEach(element => {
        database.ref(`LED/led_${element}`).set({
            turnedOn: false
        });
    });

}

function statusAccepted() {
    if (!output.textContent) {
        output.textContent = 'Order is Accepted!';
        ledOn(2);
    }
    else {
        error.textContent = "Order cannot be Accepted after decline!"
    }
}
function statusCompleted() {
    if (output.textContent === 'Order is Accepted!') {
        output.textContent = 'Order is Completed!';
        ledOn(3);
    }
    else {
        error.textContent = 'Order must be accepted first!';
    }
}
function statusDeclined() {
    if (output.textContent === 'Order is Completed!') {
        error.textContent = "Order is already Completed!";
    }
    else {
        output.textContent = 'Order is Declined!';
        ledOff();
    }
}

function statusReturned() {
    ledOff();
}

const returnButton = document.getElementById('returnButton');
returnButton.addEventListener('click', function () {
    window.location.href = `./index.html`;
});