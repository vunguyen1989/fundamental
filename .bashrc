parse_git_branch() {
     git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/'
}
export PS1="\u@\h \[\e[32m\]\w \[\e[91m\]\$(parse_git_branch)\[\e[00m\]$ "
source $HOME/.cargo/env

source <(kubectl completion bash)

#my alias
alias Task="vim /home/vunn/Documents/task.txt"
alias Repo="cd /home/vunn/repo"
alias Myrepo="cd /home/vunn/MyRepo"
alias Tips="vim /home/vunn/MyRepo/Fundamental/tips.txt"
alias Funda="cd /home/vunn/MyRepo/Fundamental"
alias Force_build="docker-compose up --force-recreate --build"
alias Start_rabbit="docker container start some-rabbit"
. "$HOME/.cargo/env"
