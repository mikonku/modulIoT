static const char HTTP_HEADER[] PROGMEM          = R"=====(

<!DOCTYPE html>
<html lang='en'>
	<head>
		<meta charset='UTF-8'>
			<meta name='viewport' content='width=device-width, initial-scale=1, user-scalable=no'/>
			<title>{v}</title>
)=====";

static const char HTTP_STYLE[] PROGMEM           = R"=====(

		<style>
			.c{text-align: center;} 
			div,input{padding:5px;font-size:1em;} 
			input{width:95%;} 
			body{text-align: center;font-family:verdana;} 
			button{
			border:0;
			border-radius:0.3rem;
			background-color: #4CAF50; /* Green */
			color:#fff;
			line-height:2.4rem;
			font-size:1.2rem;
			width:100%;
			border-radius: 50px;
			} 
			.q{float: right;width: 64px;text-align: right;} 
			.l{background: url(\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAALVBMVEX///8EBwfBwsLw8PAzNjaCg4NTVVUjJiZDRUUUFxdiZGSho6OSk5Pg4eFydHTCjaf3AAAAZElEQVQ4je2NSw7AIAhEBamKn97/uMXEGBvozkWb9C2Zx4xzWykBhFAeYp9gkLyZE0zIMno9n4g19hmdY39scwqVkOXaxph0ZCXQcqxSpgQpONa59wkRDOL93eAXvimwlbPbwwVAegLS1HGfZAAAAABJRU5ErkJggg==\") no-repeat left center;background-size: 1em;}
		</style>
)=====";

static const char HTTP_SCRIPT[] PROGMEM          = R"=====(

			<script>
				function c(l){
					document.getElementById('s').value=l.innerText||l.textContent;document.getElementById('p').focus();
				}
				
			</script>
)=====";

static const char HTTP_HEADER_END[] PROGMEM      = R"=====(

		</head>
		<body>
			<div style='text-align:left;display:inline-block;min-width:260px;'>
)=====";

static const char HTTP_PORTAL_OPTIONS[] PROGMEM  = R"=====(
				
				<form action='/0wifi' method='get'>
					<button>Configure WiFi</button>
				</form>
				<br/>
				
				<form action='/token' method='get'>
					<button>Token</button>
				</form>
				<br/>

				<form action='/i' method='get'>
					<button>Info</button>
				</form>
				<br/>
				<form action='/r' method='post'>
					<button style='background-color: #f44336;'>Reset</button>
				</form>
)=====";

//				<form action='/wifi' method='get'>
//					<button>Configure WiFi</button>
//				</form>
//				<br/>
				

static const char HTTP_ITEM[] PROGMEM            = R"=====(

				<div>
					<a href='#p' onclick='c(this)'>{v}</a>&nbsp;
					<span class='q {i}'>{r}%</span>
				</div>
)=====";

static const char HTTP_FORM_START[] PROGMEM      = R"=====(

				<form method='post' action='wifisave'>
					<input id='s' name='s' length=32 placeholder='SSID' required>
						<br/>
						<input id='p' name='p' length=64 type='password' placeholder='password'>
							<br/>
)=====";

static const char HTTP_FORM_TOKEN[] PROGMEM      = R"=====(

							<form method='post' action='tokensave'>
								<input id='token' name='token' length=32 placeholder='Auth Token' placeholder='Username' autocomplete='off' required>
									<br/>
)=====";

static const char HTTP_FORM_PARAM[] PROGMEM      = R"=====(

									<br/>
									<input id='{i}' name='{n}' maxlength={l} placeholder='{p}' value='{v}' {c}>
)=====";

static const char HTTP_FORM_END[] PROGMEM        = R"=====(

										<br/>
										<button type='submit'>save</button>
									</form>
									<br/>
)=====";

static const char HTTP_BACK[] PROGMEM        = R"=====(
									<a href='/'>
										<button style='background-color: #e7e7e7; color: black;'>back</button>	
									</a>
)=====";

static const char HTTP_SCAN_LINK[] PROGMEM       = R"=====(

									<br/>
									<br/>
									<br/>
									<div class='c'>
										<a href='/wifi'>
										<button style='background-color: #008CBA;'>scan!</button>
										</a>
									</div>
)=====";

static const char HTTP_SAVED[] PROGMEM           = R"=====(

									<div>Credentials Saved
										<br />Trying to connect ESP to network.
										<br />If it fails reconnect to AP to try again
									</div>
)=====";

static const char HTTP_END[] PROGMEM             = R"=====(

								</div>
							</body>
						</html>
)=====";

static const char LOGO[] PROGMEM = R"=====(
<img src="data:image/png;base64,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" alt="prc" style="width:1cm;height:1cm;" />
)=====";

