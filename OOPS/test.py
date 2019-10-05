def is_bust(score):
    if score<0 or score>31:
        return True
    else:
        return False
    
def is_special(cardvalue):
    if cardvalue in [1,2,3]:
        return True
    
    return False
    

class Achieve31():
    
    #Init Cards
    def __init__(self):
        self.mincard = 0
        self.maxcard = 10
        self.cards = np.arange(self.mincard,self.maxcard+1)
        self.gamethreshold = 31
        self.reset()
        self.playersum = 0
        self.dealercard = 0
        self.dealersum = 0
        self.actions = (0,1)
        # First Card, Second Card, Third Card State
        # 0 - No Card Arrived, 1 - Card Arrived and Used 2 - Card Avbl not used
        
        self.special_cards = {
            1:0,
            2:0,
            3:0
        }
        
        self.dealer_special_cards = {
            1:0,
            2:0,
            3:0
        }
        
        
    def drawCard(self):
        cardvalue = np.random.choice(self.cards)
        
        p = np.random.random()
        if p<=2/3:
            #Black Card
            return cardvalue
            
        else:
            #Red Card
            return -cardvalue
        
    def sumHand(self,current_sum,special_cards):
        
        if current_sum>31 and special_cards[3]==2:
            special_cards[3] = 1
            current_sum -= 10
        
        elif current_sum>31 and special_cards[2]==2:
            special_cards[2] = 1
            current_sum -= 10
        
        elif current_sum>31 and special_cards[1]==2:
            special_cards[1] = 1
            current_sum -= 10
            
        
        elif special_cards[3]==1 and special_cards[2]==1 and current_sum+20<=31:
            current_sum += 20
            special_cards[3] = 2
            special_cards[2] = 2
            
        elif special_cards[2]==1 and special_cards[1]==1 and current_sum+20<=31:
            current_sum += 20
            special_cards[2] = 2
            special_cards[1] = 2
        
        elif special_cards[3]==1 and special_cards[1]==1 and current_sum+20<=31:
            current_sum += 20
            special_cards[3] = 2
            special_cards[1] = 2
        
        elif special_cards[3]==1 and current_sum + 10 <= 31:
            current_sum +=10
            special_cards[3] = 2
        
        elif special_cards[2]==1 and current_sum + 10 <= 31:
            current_sum +=10
            special_cards[2] = 2
        
        elif special_cards[1]==1 and current_sum + 10 <= 31:
            current_sum +=10
            special_cards[1] = 2
        
        return current_sum,special_cards 
        
    def getObservation(self):
        player_sum, self.special_cards = self.sumHand(self.playersum,self.special_cards)
        return player_sum, self.dealercard,self.special_cards
    

    def reset(self):
        card1 = self.drawCard()
        card2 = self.drawCard()
        
        self.playersum = card1
        self.dealercard = card2
        self.dealercard += card2
        
        if is_special(card1):
            self.special_cards[card1] = 1
            
        if is_special(card2):
            self.dealer_special_cards[card2] = 1
            
        return self.getObservation()
    
    
    def step(self,action):
        terminated = None
        reward = None
        
        if action==1:
            card = self.drawCard()
            print(card)
            self.playersum += card
            
            if is_special(card) and self.special_card[card]==0:
                self.special_card[card] = 1
            
            self.playersum,self.special_cards = self.sumHand(self.playersum,self.special_cards)
            
            if is_bust(self.playersum):
                terminated = True
                reward = -1
            else:
                terminated = False
                reward = 0

        elif action==0:
            terminated = True
            self.dealer,self.dealer_special_cards  = sumHand(self.dealersum,self.dealer_special_cards)
            
            #Dealer Game Play according to Fixed Policy
            while s>0 and  s<25:
                card += self.drawCard()
                if is_special(card) and self.dealer_special_cards[card]==0:
                    self.dealer_special_cards[card] = 1
                
                self.dealersum += card
                self.dealersum,self.dealer_special_cards  = sumHand(self.dealersum,self.dealer_special_cards)
                
            # Compare Scores for Final Reward
            ds = self.dealersum
            ps = self.playersum
            
            if ds<0 or ds>self.gamethreshold or ds<ps:
                reward =1
            elif ds==ps:
                reward = 0
            elif ds>ps:
                reward = -1
                
        state = self.getObservation()
        return state,reward,terminated