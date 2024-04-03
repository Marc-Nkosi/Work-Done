<!DOCTYPE html>
<html>
  <head>
    <title>
      User image
    </title>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/webcamjs/1.0.25/webcam.min.js"></script>
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.1.3/css/bootstrap.min.css"
    />
    <style type="text/css">
      #results {
        padding: 20px;
        border: 1px solid;
        background: #ccc;
      }
    </style>
  </head>
  <body>
    <div class="container">
      <h1 class="text-center">
        Please take snapshot and submit before you can proceed.
      </h1>

      <form method="POST" action="http://localhost/lebo/storeImage.php">
        <div class="row">
          <div class="col-md-6">
            <div id="my_camera"></div>
            <br />
            <input required="required" 
              type="button"
              value="Take Snapshot"
              onClick="take_snapshot()"
            />
            <input type="hidden" name="image" class="image-tag" required/>
          </div>
          <div class="col-md-6">
            <div id="results">Your captured image will appear here...</div>
          </div>
          <div class="col-md-12 text-center">
            <br />
            <button id="myP1" style="display: none;" class="btn btn-success">Submit</button>
          </div>
        </div>
      </form>
    </div>

    <!-- Configure a few settings and attach camera -->
    <script language="JavaScript">
      Webcam.set({
        width: 490,
        height: 390,
        image_format: "jpeg",
        jpeg_quality: 90,
      });

      Webcam.attach("#my_camera");

      function take_snapshot() {
        Webcam.snap(function (data_uri) {
          $(".image-tag").val(data_uri);
          document.getElementById("results").innerHTML =
            '<img src="' + data_uri + '"/>';


            document.getElementById("myP1").style.display = "block";

        });
      }
    </script>
  </body>
</html>