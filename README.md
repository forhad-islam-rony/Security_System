﻿# Security_System
 Features
 1.Admin and User
    1.1.Only admin can access the admin option.Here admin can see how many pepople registered in this system and admin can also see their details(i.g,name,age,email,username,phone Number but not password(beacuse it is hidden for all)
    1.2.in user option people can chosse Register or Login option(if previously registered than no need to regiser again because all data are saved in file.
 2.Regiser and Login
    2.1 In register,there need some information.Users can register an account by using individual phone number.
    2.2 In Login,Users can login by using username and password(if users forget password than they can set new password by using phone number
 Note:- Actual password did't store in the file.while storing password,password will be encrypted(So,Account will be more secure and no one can detect the actual password.
 
 ---Users can view their profile
 ---users can change their password
 ---Users can delete their ID from the system
 3.File and Console application
  --The Security System provides the flexibilty to work as a file-based application,where Users can create and login their account
  4.Record
    --Users information are saved in security_file.txt fie.
    
    Note:- Here Register and Login are highlighted but my main focus was to secure password and identify duplicate id.Therefore,here encrypted and decrypted fuction used and here also masking the password.
