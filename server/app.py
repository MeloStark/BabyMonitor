import logging
from flask import Flask, render_template

app = Flask(__name__)

# ログの設定
log_formatter = logging.Formatter("%(asctime)s - %(levelname)s - %(message)s")
log_file = "server/logs/server.log"

# ファイルハンドラ
file_handler = logging.FileHandler(log_file)
file_handler.setFormatter(log_formatter)
file_handler.setLevel(logging.INFO)

# エラーハンドラ
error_handler = logging.FileHandler("server/logs/error.log")
error_handler.setFormatter(log_formatter)
error_handler.setLevel(logging.ERROR)

# アプリケーションにログハンドラを追加
app.logger.addHandler(file_handler)
app.logger.addHandler(error_handler)

@app.route("/")
def index():
    app.logger.info("Index page accessed.")
    return render_template("index.html")

@app.errorhandler(404)
def not_found(e):
    app.logger.error(f"404 error: {e}")
    return "<h1>404: Page not found</h1>", 404

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080, debug=True)