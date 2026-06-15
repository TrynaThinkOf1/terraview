# TerraView
### shitty little toy C project to test out the Zed editor

---

## What does it do?
#### uses ncurses to render a spinning mercator projection, I mean the globe, on your terminal
#### terminal must be at least 80x40, does not require color.

---

# Installation
### why the hell do you wanna install this?
```bash
# for Linux:
#   `apt install libncurses-dev`
#   `dnf install ncurses-devel`
#   `pacman -S ncurses`
# macOS has ncurses preinstalled, otherwise:
#   `brew intall ncurses`

git clone https://github.com/TrynaThinkOf1/terraview.git
cd terraview
make

./terraview

# you could also move this binary into your $PATH
# and access it globally via `terraview` but I
# couldn't fathom why you would do that
```
### if you want this on Windows, do **not** let me know.
### port it yourself, and 🖕 Windows