<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// Database configurations
define("DB_HOST", "localhost");
define("DB_UNAME", "quiz_user_2024");
define("DB_PASS", "Qz!8wD#pK3vR");
define("DB_DNAME", "quiz");

// Create connection
$conn = mysqli_connect(DB_HOST, DB_UNAME, DB_PASS, DB_DNAME);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
?>
