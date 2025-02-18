#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

typedef Account		t;

int	getNbAccounts(){
    return _accountIndex;
}
int	getTotalAmount(){
    return _amount;
}

int	getNbDeposits(){
    return _nbDeposits;
}
int	getNbWithdrawals(){
    return _nbWithdrawals;
}
void	displayAccountsInfos(){
    std::cout << "Account Nb: " << _accountIndex << std:: endl;
    std::cout << "Amount: " << _amount << std:: endl;
    std::cout << "Nb of Deposits: " << _nbDeposits << std:: endl;
    std::cout << "Nb of withdraw: " << _nbWithdrawals << std:: endl;
}

Account::Account(int initial_deposit ) 
        : _accountIndex(_nbAccounts++),
          _amount(initial_deposit), 
          _nbDeposits(0), 
          _nbWithdrawals(0)
        {
            _totalAmount += _amount;
            std::cout << "Thanks for opening account in GlobalBanksters United" << std::endl;
        }

Account::~Account( void ){
        std::cout << "Your account closed, Thanks you"<< std::endl;
}

void	makeDeposit( int deposit ){
        Account::_totalAmount += deposit;
        _nbDeposits++;
}
bool	makeWithdrawal( int withdrawal ){
        Account::_totalAmount -= withdrawal;
        _nbWithdrawals++;
}
int		checkAmount( void ) const{
        return _totalAmount;
}
void	displayStatus( void ) const{
        std::cout << _totalAmount << std::endl;
}
// void Account::_displayTimestamp() {
//     std::time_t now = std::time(nullptr);
//     std::tm* localTime = std::localtime(&now);
//     char buffer[20];
//     std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
//     std::cout << buffer;
// }






static void	_displayTimestamp( void );

int				_accountIndex;
int				_amount;
int				_nbDeposits;
int				_nbWithdrawals;

Account( void );

