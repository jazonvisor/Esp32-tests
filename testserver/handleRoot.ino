void handleRoot() {
  String html = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<style>body{font-family:Arial, sans-serif; text-align:center;}table{width:100%;}th{background-color:#f1f1f1;}th,td{padding:8px; text-align:center; border-bottom:1px solid #ddd;}tr:hover{background-color:#f1f1f1;}input[type='number']{width:50%; padding:8px; margin:8px 0;}input[type='submit']{background-color:#4CAF50; color:white; padding:14px 20px; border:none; cursor:pointer; width:60%;}</style>";
  html += "</head><body><h1>Термостат на 16 каналов</h1>";
  html += "<table><tr><th>Датчик</th><th>Температура, ºC</th><th>Уставка, ºC</th><th>Мёртвая зона регулирования, ºC</th><th>Реле</th></tr>";
  html += "</table></form></body></html>";

  server.send(200, "text/html; charset=utf-8", html);
}
