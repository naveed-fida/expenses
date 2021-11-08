make
mkdir $HOME/.expenses
cp bin/expenses $HOME/.expenses/

touch $HOME/.bash_profile
echo "export EXPENSES_DATA_DIR=\"\$HOME/.expenses\"" >> $HOME/.bash_profile
export EXPENSES_DATA_DIR="$HOME/.expenses"
echo "export PATH=\"\$PATH:\$EXPENSES_DATA_DIR\"" >> $HOME/.bash_profile
export PATH="$PATH:$EXPENSES_DATA_DIR"
make clean