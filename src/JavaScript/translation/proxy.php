<?php
$url = $_GET['path'];
$session = curl_init($url);

// Don't return HTTP headers. Do return the contents of the call.
curl_setopt($session, CURLOPT_HEADER, false);
curl_setopt($session, CURLOPT_RETURNTRANSFER, true);
// Make the call.
$html = curl_exec($session);

// The web service returns HTML.
header("Content-Type: text/html; charset=UTF-8");

echo $html;
curl_close($session);
?>
