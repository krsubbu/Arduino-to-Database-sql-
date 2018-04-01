<?php
    $dbconnect = mysqli_connect("localhost",root,"");
    $dbselect = mysqli_select_db($dbconnect,"test");
 $sql = "INSERT INTO `test`.`sensor` (`value`) VALUES ('".$_GET["value"]."')";    
    mysqli_query($dbconnect,$sql);


?>