<?php
$url=$_SERVER['REQUEST_URI'];
header("Refresh: 1; URL=$url");  // Refresh the webpage every 1 seconds
?>
<html>
<head>
    <title>Temperature data</title>
</head>
    <body>
        <h1>DATA</h1>

    <table border="2" cellspacing="4" cellpadding="6">
      <tr>
            <td>ID</td>
            <td>Time</td>
            <td>Reading </td>
      </tr>

<?php
    // Connect to database

   // IMPORTANT: If you are using XAMPP you will have to enter your computer IP address here, if you are using webpage enter webpage address (ie. "www.yourwebpage.com")
    $con=mysqli_connect("localhost","root","","test");

    // Retrieve all records and display them
    $result = mysqli_query($con,"SELECT * FROM `sensor` ORDER BY `id` DESC");

    // Process every record

    while($row = mysqli_fetch_array($result))
    {
        echo "<tr>";
        echo "<td>" . $row['id'] . "</td>";
        echo "<td>" . $row['date and time'] . "</td>";
        echo "<td>" . $row['value'] . "</td>";
        echo "</tr>";

    }

    // Close the connection
    mysqli_close($con);
?>
    </table>
    </body>
</html>
