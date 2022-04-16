<!DOCTYPE html>
<!--
Gra Dino v. 1.5 by Makary Krupicz - Cookie852
Kod / omowienie / linki: https://oki.org.pl/dino
Wersje:
1.0 - Strona www z tekstem
1.1 - canvas (plotno)
1.2 - ziemia
1.3 - funkcje plansza/ziemia
1.4 - kaktus
1.5 - Animacja!
-->
<html>
<head>
</head>
 
<body>

<div>
<strong>Gra Dino v1.5 by CodeMonster</strong>   
<br />Dino idzie przez pustynie.
</div>

<canvas id="plansza_canvas" width="600px" height="200px">
</canvas>

<script>
let plansza, rysowanie;
let kaktus_x;

kaktus_x = 550;

plansza = document.getElementById("plansza_canvas");
rysowanie = plansza.getContext("2d");  

function RysujPlansze() {
   rysowanie.fillStyle = "rgb(249,218,255)";    
   rysowanie.fillRect(0,0, 600,200);
}
function RysujZiemie() {
   rysowanie.fillStyle = "rgb(69,0,33)";    
   rysowanie.fillRect(0,170, 600,5);
}
function RysujKaktus(x) {
   rysowanie.fillStyle = "rgb(36,170,0)";    
   rysowanie.fillRect(x,140,10,30);
}

function Gra() {
   RysujPlansze();
   RysujZiemie();
   RysujKaktus(kaktus_x);
   kaktus_x = kaktus_x - 1;
   if ( kaktus_x < 0 )
      kaktus_x = 550;
}

setInterval(Gra, 10); //100 razy na sekund - co 10 ms

</script>

</body> 
</html>