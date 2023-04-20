<html>
<head>
    <h1>EECS 348 Lab Seven Practice Four</h1>
</head>
<body>
    <?php
    $size = $_POST['size'];
    echo "<table style='border-collapse: collapse;'>";
    for ($i = 0; $i <= $size; $i++) {
        echo "<tr>";
        for ($j = 0; $j <= $size; $j++) {
            if ($i === 0 && $j === 0) {
                echo "<td style='border: 1px solid black;'></td>";
            } elseif ($i === 0) {
                echo "<td style='border: 1px solid black;'>$j</td>";
            } elseif ($j === 0) {
                echo "<td style='border: 1px solid black;'>$i</td>";
            } else {
                $result = $i * $j;
                echo "<td style='border: 1px solid black;'>$result</td>";
            }
        }
        echo "</tr>";
    }
    echo "</table>";
    ?>
</body>
</html>