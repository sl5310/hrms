<?php
session_start();
// Delete certain session
session_destroy();

header('Location: ../login.php');
?>