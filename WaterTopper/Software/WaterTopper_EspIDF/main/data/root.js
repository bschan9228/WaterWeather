var ws = null;

function insertMsg(user, message) {
    if (message != null) document.getElementById("chat").innerHTML = `<p>${user}: ${message} </p>` + document.getElementById("chat").innerHTML;
}

function sendMsg() {
    ws.send(buildMsg());
}

//FIX  failed: Could not decode a text frame as UTF-8.
function buildMsg() {
    message = document.getElementById("message").value;
    if (message != "") return message;

}

function isJsonString(str) {
    try {
        JSON.parse(str);
    } catch (e) {
        return false;
    }
    return true;
}

function beginSocket() {
    ws = new WebSocket('ws://'+document.location.host+'/ws');

    ws.onmessage = function(e){
        console.log(e.data);

        if (isJsonString(e.data)) {
                const msgdata = JSON.parse(e.data);    
                insertMsg(msgdata["user"], msgdata["message"]);
            
        }
    }        
}


