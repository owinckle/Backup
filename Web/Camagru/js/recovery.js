var button 	= document.getElementById('recovery');
var label 	= document.getElementById('label');
var input 	= document.getElementById('inputs');
var email 	= document.getElementById('emailLabel');
function getCode() {
	var code = Math.floor((Math.random() * 10000) + 1);
	return (code);
}
button.addEventListener("click", function() {
	if (button.value == "Send Recovery Email" || button.value == "Error - Send New Recovery Code")
	{
		button.value 			= "Sending Recovery Code";
		button.style.background = "#cc6161";
		var email 				= input.value;
		emailLabel.innerHTML 	= input.value;
		code 					= getCode();
		input.value 			= "";

		var xhr_code = new XMLHttpRequest();
		var mailcode = new FormData();
		mailcode.append('action', 'mailCode');
		mailcode.append('email', email);
		mailcode.append('code', code);
		xhr_code.open('POST', 'ajax.php');
		xhr_code.send(mailcode);
		setTimeout(function () {
			button.style.background 	= "rgb(52, 138, 42)";
			button.value			 	= "Sent";
			setTimeout(function () {
				button.style.background = "#df2940";
				label.innerHTML 		= "Enter Your Recovery Code";
				button.value 			= "Submit Recovery Code";
			}, 1500);
		}, 1500);
	}
	if (button.value == "Submit Recovery Code")
	{	
		var enteredCode 		= input.value;
		input.value 			= "";
		button.value 			= "Validating Code";
		button.style.background = "#cc6161";
		setTimeout(function () {
			if (enteredCode == code)
			{
				button.style.background = "#df2940";
				input.type 				= "password";
				label.innerHTML 		= "Enter your new password";
				button.value 			= "Change Password";
			}
			else
			{
				button.style.background = "#df2940";
				input.type 				= "text";
				emailLabel.innerHTML 	= "";
				button.value			= "Error - Send New Recovery Code";
				label.innerHTML 		= "Enter your email";
			}
		}, 3000);
	}
	if (button.value == "Change Password")
	{
		var email 		= emailLabel.innerHTML;
		var password 	= input.value;

		var xhr_confirm = new XMLHttpRequest();
		var changepass = new FormData();
		changepass.append('action', 'changePass');
		changepass.append('email', email);
		changepass.append('password', password);
		xhr_confirm.open('POST', 'ajax.php');
		xhr_confirm.send(changepass);
		xhr_confirm.onreadystatechange = function () {
		  var DONE = 4;
		  var OK = 200;
		  if (xhr_confirm.readyState === DONE) {
		    if (xhr_confirm.status === OK) {
		    	var output = xhr_confirm.responseText;
		    	button.style.background = "#cc6161";
				button.value 			= "Checking Your Account";
				setTimeout(function () {
					if (output == "found"){
						button.style.background = "rgb(52, 138, 42)";
						button.value 			= "Password Successfully Changed";
						setTimeout(function () {
							button.value 	= "Redirecting...";
							window.location = "../auth/login";
						}, 1000);
					}
					if (output == "email"){
						button.value 				= "Email Does Not Exist";
						setTimeout(function () {
							button.style.background = "#df2940";
							input.value 			= "";
							input.type 				= "text";
							emailLabel.innerHTML 	= "";
							button.value 			= "Error - Send New Recovery Code";
							label.innerHTML 		= "Enter your email";
						}, 1000);
					}
					if (output == "len"){
						button.value 				= "Password need at least 8 characters";
						setTimeout(function () {
							button.style.background = "#df2940";
							input.value 			= "";
							input.type 				= "text";
							emailLabel.innerHTML 	= "";
							button.value 			= "Error - Send New Recovery Code";
							label.innerHTML 		= "Enter your email";
						}, 2500);

					}
					if (output == "alpha"){
						button.value 				= "Password need to contain one letter";
						setTimeout(function () {
							button.style.background = "#df2940";
							input.value 			= "";
							input.type 				= "text";
							emailLabel.innerHTML	= "";
							button.value 			= "Error - Send New Recovery Code";
							label.innerHTML 		= "Enter your email";
						}, 2500);
					}
					if (output == "nbr"){
						button.value 				= "Password need to contain one number";
						setTimeout(function () {
							button.style.background = "#df2940";
							input.value 			= "";
							input.type 				= "text";
							emailLabel.innerHTML 	= "";
							button.value 			= "Error - Send New Recovery Code";
							label.innerHTML 		= "Enter your email";
						}, 2500);
					}
				}, 2000);
			}
		    }
		  }
		};
	});