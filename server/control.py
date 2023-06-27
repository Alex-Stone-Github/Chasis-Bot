import http.server
import json
import keyboard

obj = {
    "hi": [1, 2, 3],
    "hithere": True,
    "hithere3": "What is this"
}

class Server(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/json")
        self.end_headers()
        cmd = "Nothing"
        if keyboard.is_pressed('w'):
            cmd = "forward"
        if keyboard.is_pressed('s'):
            cmd = "backward"
        if keyboard.is_pressed('a'):
            cmd = "left"
        if keyboard.is_pressed('d'):
            cmd = "right"
        command = {"message": cmd}
        self.wfile.write(bytes(json.dumps(command), "utf-8"))

server = http.server.HTTPServer(("localhost", 8000), Server)
try:
    print("Starting server on port localhost:8000")
    server.serve_forever()
except KeyboardInterrupt:
    pass
server.server_close()
print("stopped server")