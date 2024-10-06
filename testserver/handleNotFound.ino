void handleNotFound() {
  server.send(404, "text/html; charset=utf-8", "404: Страница не найдена.");
}
