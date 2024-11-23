# Strategic Programming Exercise 🎮

情報工学実験Ⅳ - 戦略プログラミング演習のためのリポジトリです。

## Setup with Dev Containers 📦

Strategic Programming Exercise の開発環境を Dev Containers で簡単に立ち上げることができます。

### Attention

- 事前に [Docker](https://docs.docker.com/get-docker) と [Visual Studio Code](https://code.visualstudio.com) をインストールしておく必要があります。

### 1. clone git repository

```bash
git clone "https://github.com/nitic-csx-iv-t2-w8-2024/strategic-programming-exercise" && cd "./strategic-programming-exercise"
```

### 2. launch container

VSCodeの拡張機能 [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) を使用してコンテナを起動してください。

### 3. build and run

引数 `PRAC` は演習のディレクトリ名 (`chicken-game` または `prisoners-dilemma`) を指定してください。  
`make dev` でビルドと実行を同時に行うことができます。

```bash
make dev PRAC=prisoners-dilemma
```

その他、以下のコマンドを使用することができます。

- `make build`
- `make start`
- `make clean`
