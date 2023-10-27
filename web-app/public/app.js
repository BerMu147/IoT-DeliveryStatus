// Database Paths - TEST
var dataFloatPath = 'test/float';
var dataIntPath = 'test/int';

var dataLedpath = 'LED';
// Database Paths - REAL
var dataAccept = 'Accepted';
var dataComplete = 'Completed';
var dataDecline = 'Declined';

// Get a database reference - TEST
const databaseFloat = database.ref(dataFloatPath);
const databaseInt = database.ref(dataIntPath);
const databaseLed = database.ref(dataLedpath);
// REAL
// const databaseAccept = database.ref(dataAccept);
// const databaseComplete = dataAccept.ref(dataComplete);
// const databaseDecline = databaseDecline.ref(dataDecline);

// Variables to save database current values
var floatReading;
var intReading;
// REAL //
var accept;
var complete;
var decline;

function ledOn(){
    databaseLed.set({
        status: "ON"
    })
}

function ledOff(){
    databaseLed.set({
        status: "OFF"
    })
}

// Attach an asynchronous callback to read the data
databaseFloat.on('value', (snapshot) => {
  floatReading = snapshot.val();
  console.log(floatReading);
  document.getElementById("reading-float").innerHTML = floatReading;
}, (errorObject) => {
  console.log('The read failed: ' + errorObject.name);
});

databaseInt.on('value', (snapshot) => {
  intReading = snapshot.val();
  console.log(intReading);
  document.getElementById("reading-int").innerHTML = intReading;
}, (errorObject) => {
  console.log('The read failed: ' + errorObject.name);
});
