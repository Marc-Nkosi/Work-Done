<?php


$d=strtotime("today");
$todayDate =  date("Y-m-d", $d) ;

date_default_timezone_set("Etc/GMT-2");
$time = date("h:i:sa");

$fullTime = str_replace(":","-",$time);

$fullDate = $todayDate ."-". $fullTime;

echo $fullDate;

   
    $img = $_POST['image'];
    $folderPath = "uploads/";
  
    $image_parts = explode(";base64,", $img);
    $image_type_aux = explode("image/", $image_parts[0]);


    $image_type = $image_type_aux[1];
  
    $image_base64 = base64_decode($image_parts[1]);
    // $fileName = uniqid() . '.png';
     $fileName = $fullDate . '.png';

    //$fileName = $fullDate . '.png';

    echo "file name is " . $fileName;
  
    $file = $folderPath . $fileName;
    file_put_contents($file, $image_base64);
  
    print_r($fileName);


        //echo "You have successfully login"; 

       //header("Location: http://hjspecialistclinic.co.za/clinic/login.php");

       header("Location: clinic/signin");


        "<br>";
  
?>