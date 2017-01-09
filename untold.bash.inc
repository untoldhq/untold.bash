# A variable pointing to the directory from which untold.bash is being imported
source_dir=$(dirname $BASH_SOURCE)

### Aliases
# Open specified files in Sublime Text
# "s ." will open the current directory in Sublime
alias s='/Applications/Sublime\ Text.app/Contents/SharedSupport/bin/subl'
# Color LS
colorflag="-G"
alias ls="command ls ${colorflag}"
alias l="ls -lF ${colorflag}" # all files, in long format
alias la="ls -laF ${colorflag}" # all files inc dotfiles, in long format
alias lsd='ls -lF ${colorflag} | grep "^d"' # only directories
alias be="bundle exec"
alias bi="bundle install"
#Run bundle install locally to this directory
alias bil="bundle install --path vendor/bundle"

# Quicker navigation
alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias .....="cd ../../../.."
alias o="open ." #Open current directory in Finder

# Shortcuts to my Code folder in my home directory
alias sites="cd ~/Sites"
alias docs="cd ~/Documents"
alias down="cd ~/Downloads"

# Enable aliases to be sudo’ed
alias sudo='sudo '
# Colored up cat!
# You must install Pygments first - "sudo easy_install Pygments"
alias c='pygmentize -O style=monokai -f console256 -g'
# Git
# You must install Git first - ""
alias gs='git status'
alias ga='git add .'
alias gc='git commit -m' # requires you to type a commit message
alias gp='git push'
alias solr='cd ~/solr-4.1.0/example && java -jar start.jar'
alias bfg='java -jar ~/Utils/bfg-1.12.12.jar'
### Prompt Colors
# Modified version of @gf3’s Sexy Bash Prompt
# (https://github.com/gf3/dotfiles)
if [[ $COLORTERM = gnome-* && $TERM = xterm ]] && infocmp gnome-256color >/dev/null 2>&1; then
    export TERM=gnome-256color
elif infocmp xterm-256color >/dev/null 2>&1; then
    export TERM=xterm-256color
fi
if tput setaf 1 &> /dev/null; then
    tput sgr0
    if [[ $(tput colors) -ge 256 ]] 2>/dev/null; then
        BLACK=$(tput setaf 190)
        MAGENTA=$(tput setaf 9)
        ORANGE=$(tput setaf 172)
        BRAND=$(tput setaf 205)
        PURPLE=$(tput setaf 141)
        WHITE=$(tput setaf 7)
    else
        BLACK=$(tput setaf 190)
        MAGENTA=$(tput setaf 5)
        ORANGE=$(tput setaf 4)
        BRAND=$(tput setaf 2)
        PURPLE=$(tput setaf 1)
        WHITE=$(tput setaf 7)
    fi
    BOLD=$(tput bold)
    RESET=$(tput sgr0)
else
    BLACK="\033[01;30m"
    MAGENTA="\033[1;31m"
    ORANGE="\033[1;33m"
    BRAND="\033[1;32m"
    PURPLE="\033[1;35m"
    WHITE="\033[1;37m"
    BOLD=""
    RESET="\033[m"
fi
export BLACK
export MAGENTA
export ORANGE
export BRAND
export PURPLE
export WHITE
export BOLD
export RESET
# Git branch details
function parse_git_dirty() {
    [[ $(git status 2> /dev/null | tail -n1) != *"nothing to commit"* ]] && echo "*"
}
function parse_git_branch() {
    git branch --no-color 2> /dev/null | sed -e '/^[^*]/d' -e "s/* \(.*\)/\1$(parse_git_dirty)/"
}
# Change this symbol to something sweet.
# (http://en.wikipedia.org/wiki/Unicode_symbols)
symbol="⚡ "
export PS1="\[$BOLD\]\[$BRAND\]\w\[$WHITE\]\$([[ -n \$(git branch 2> /dev/null) ]] && echo \" on \")\[$PURPLE\]\$(parse_git_branch)\[$WHITE\]\n$symbol\[$RESET\]"
export PS2="\[$ORANGE\]→ \[$RESET\]"
### Misc
# Only show the current directory's name in the tab
export PROMPT_COMMAND='echo -ne "\033]0;${PWD##*/}\007"'
# init z! (https://github.com/rupa/z)
# . ~/z.sh
[[ -s "$HOME/.rvm/scripts/rvm" ]] && source "$HOME/.rvm/scripts/rvm" # Load RVM into a shell session *as a function*
# source ~/.profile
[[ -s "$HOME/.rvm/scripts/rvm" ]] && . "$HOME/.rvm/scripts/rvm"
 # Load RVM function
export ANDROID_HOME=/Users/sam/Library/Android/sdk
export PATH=${PATH}:$ANDROID_HOME/tools:$ANDROID_HOME/platform-tools
export PATH="$HOME/.composer/vendor/bin:$PATH"
#PATH=${PATH}:/usr/local/mysql/bin

### Check for latest version
cd $source_dir
git remote update >> /dev/null
output=$(git status -uno | grep up-to-date)
if [ -z "$output" ]
then
echo "⚠️   ${BOLD}${BRAND}Your untold.bash is out of date.$RESET   ⚠️"
fi
cd ~
