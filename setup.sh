make
mkdir $HOME/.expenses
touch $HOME/.expenses/data
cp bin/expenses $HOME/.expenses/

touch $HOME/.bash_profile
echo "export PATH=\"\$PATH:\$HOME/.expenses\"" >> $HOME/.bash_profile

make clean

source $HOME/.bash_profile