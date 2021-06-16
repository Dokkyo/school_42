# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    numgen.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naben-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 12:40:23 by naben-za          #+#    #+#              #
#    Updated: 2021/03/30 12:40:27 by naben-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random

while True:
	l = int(input("Enter number length: "))
	if l < 3:
		print("Give me a bigger number please")
	else:
		break

for _ in range(l):
	print(random.randint(0, 9), end="")
print()
input()
