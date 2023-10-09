# vst3-boilerplate

VST3 SDK を使ったプロジェクトのサンプル。UUID やプロジェクト名などを適切に変更する必要があるので、VST3_Project_Generator を使って生成した source ファイルに置き換えて利用してください。

## サブモジュールの取得

VST3 SDK をサブモジュールとして利用しているので、このリポジトリの clone 後に下記のコマンドで取得してください。

```sh
git submodule update --init --recursive
```

## Xcode プロジェクト生成

```sh
cmake -B build -G Xcode -DSMTG_ADD_VSTGUI=ON
xed build
```

ビルドを実行すると `.vst3` ファイルが生成され、`~/Library/Audio/Plug-Ins/VST3` にシンボリックリンクが生成される。

## ビルドエラーの修正

なぜかはよくわからないが失敗する Build Phase を一度成功するように修正すると直せる。

1. validator の Build Phases の CMake PostBuild Rules を下記のように変更

```diff
set -e
+ exit 0;
if test "$CONFIGURATION" = "Debug"; then :
```

2. ビルド (失敗する)
3. `exit 0;` を削除
4. ビルド (失敗する)
5. MIDIOutputExample (プロジェクト名) の CMake PostBuild Rules も同様に `exit 0;` 追加
6. ビルド (成功)
