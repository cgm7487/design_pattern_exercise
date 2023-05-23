from abc import ABC, abstractclassmethod

class PaymentStrategy(ABC):
    @abstractclassmethod
    def pay(self, amount):
        pass
    
class CreditCardStrategy(PaymentStrategy):
    def pay(self, amount):
        print(f"Paying {amount} using credit card.")
        
class PaypalPayment(PaymentStrategy):
    def pay(self, amount):
        print(f"Paying {amount} using Paypal.")
        
class StripePayment(PaymentStrategy):
    def pay(self, amount):
        print(f"Paying {amount} using Stripe.")
        
        
class PaymentContext:
    def __init__(self, payment_strategy: PaymentStrategy):
        self.payment_strategy = payment_strategy
        
    def set_payment_strategy(self, payment_strategy: PaymentStrategy):
        self.payment_strategy = payment_strategy
        
    def pay(self, amount):
        self.payment_strategy.pay(amount)
        
payment_context = PaymentContext(CreditCardStrategy())
payment_context.pay(100)

payment_context.set_payment_strategy(PaypalPayment())
payment_context.pay(200)

payment_context.set_payment_strategy(StripePayment())
payment_context.pay(300)
