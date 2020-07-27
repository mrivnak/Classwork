<?php
    include "navigation.php"

    for($count = 0; $count < 10; $count++) {
        switch($count % 2) {
            case 0:
                echo $count." is even<br/>";
                break;
            case 1:
                echo $count." is odd<br/>";
                break;
            default:
                echo "unknown";
                break;
        }
    }
?>