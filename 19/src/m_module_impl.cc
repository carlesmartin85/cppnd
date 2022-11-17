export module airline:ticket;

import <string>;

export namespace air{

	class AirlineTicket{
	public:
		double calculatePriceInDollars(){
			if (hasEliteSuperRewardsStatus())
			{
				return 0;
			}
			return getNumberOfMiles() * 0.1;
		}
		std::string getPassengerName() { return m_passengerName; }
		void setPassengerName(std::string name) { m_passengerName = name; }
		int getNumberOfMiles() { return m_numberOfMiles; }
		void setNumberOfMiles(int miles) { m_numberOfMiles = miles; }
		bool hasEliteSuperRewardsStatus() { return m_hasEliteSuperRewardsStatus; }
		void setHasEliteSuperRewardsStatus(bool status){
			m_hasEliteSuperRewardsStatus = status;
		}

	private:
		std::string m_passengerName{"Unknown Passenger"};
		int m_numberOfMiles{0};
		bool m_hasEliteSuperRewardsStatus{false};
    };

}