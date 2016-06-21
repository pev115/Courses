#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Coursework in Python 
from IDAPICourseworkLibrary import *
from numpy import *
from math import *


#
# Coursework 1 begins here
#
# Function to compute the prior distribution of the variable root from the data set
def Prior(theData, root, noStates):
    prior = zeros((noStates[root]), float )
# Coursework 1 task 1 should be inserted here
    
#Calculate the prior distribution : for each state of the variable
#find the number of occurances of this state in the data points and 
#divide by the total number of data points
    for i in range(noStates[root]) :
      prior[i] = list(theData[:,root]).count(i)/float(theData.shape[0])
    
# end of Coursework 1 task 1
    return prior
  
  
  
# Function to compute a CPT with parent node varP and xchild node varC from the data array
# it is assumed that the states are designated by consecutive integers starting with 0
def CPT(theData, varC, varP, noStates):
  cPT = zeros((noStates[varC], noStates[varP]), float )
# Coursework 1 task 2 should be inserte4d here
 
#for each of the states of the parent and the child variables find P(VarC|VarP) = N_candp/N_p 
#where N_x is the number of datapoints with state x 
  for i in range(noStates[varP]) :
     for j in range(noStates[varC]):
       #Find the number of occurences of state i of varP
	N_p = list(theData[:, varP]).count(i)
	# find the number of occurences of both states i and j of varP and varC
	N_candp = list(theData[theData[:,varP]==i][:,varC]).count(j)
	#divide to get the conditional probability
	#If N_p is 0 ie there is no occurence of value i in the data, this will give nan (division by 0)
	#we will allow this in order to reflect this insufficient data state.
	#Note that the bigger the dataset the lower the probability of this occuring
	cPT[j,i] = float(N_candp)/float(N_p)  
   
# end of coursework 1 task 2
  return cPT
  
  
  
# Function to calculate the joint probability table of two variables in the data set
def JPT(theData, varRow, varCol, noStates):
    jPT = zeros((noStates[varRow], noStates[varCol]), float )
#Coursework 1 task 3 should be inserted here 

#find the number of datapoints by looking at the number of rows
    dtpts = float(theData.shape[0])
#for each of the states of the two variables we want to have the JPT
    for i in range(noStates[varCol]):
      for j in range(noStates[varRow]):
	#find the number of datapoints having both those states
	#list all the datapoints in column varRow that are in a row where 
	#varCol = i and count the number of occurances of j
	N_rowandcol = list(theData[theData[:,varCol]==i][:,varRow]).count(j)
	#find the joint probability P(varRow & varCol) = N_rowandcol/dtpts
	jPT[j,i] = float(N_rowandcol)/float(dtpts)
    
# end of coursework 1 task 3
    return jPT
  
  
  
  
  
#
# Function to convert a joint probability table to a conditional probability table
def JPT2CPT(aJPT):
#Coursework 1 task 4 should be inserted here 

  for j in range( aJPT.shape[1]):
    #sum the values in the colum : eliminate the corresponding variable
    p_b = sum(aJPT[:,j])
    for i in range( aJPT.shape[0]):
    # Get the conditional probability : P(A|B) = P(A&B)/P(B) . If P(B) is in this case
    #we get nan, we will allow this as it reflects the fact that we have a data set that is
    #too small
	aJPT[i,j] =  aJPT[i,j]/float(p_b)     
	   
   
# coursework 1 taks 4 ends here
    return aJPT

#
# Function to query a naive Bayesian network
def Query(theQuery, naiveBayes): 
  rootPdf = zeros((naiveBayes[0].shape[0]), float)
# Coursework 1 task 5 should be inserted here

  for i in range(rootPdf.shape[0]): #for each of the states of the root
    #initialise the likelyhood information to 1
    likelyhood_info = float(1.0)
    for j in range(len(naiveBayes)-1): # for each of the CPT's
      #Calculate the likelyhood: the product of the conditional probabilities 
      likelyhood_info = likelyhood_info* float(naiveBayes[j+1][theQuery[j],i])
    #update the root probabilty for each state : P(R) = Prior*likelyhood_info
    rootPdf[i] = float(naiveBayes[0][i])*likelyhood_info
  
#Normalise 
  Sum =float(sum(rootPdf))
#if the sum is 0, return the distribution (no state of the root can occure)
  if Sum == 0 :
     return rootPdf

#if sum != 0 divide each element by the  sum to normalise the distribution and return   
  for k in range(len(rootPdf)):
    rootPdf[k] = rootPdf[k]/Sum
   
# end of coursework 1 task 5
  return rootPdf
  
  
#
# End of Coursework 1

#
# Coursework 2 begins here
#
# Calculate the mutual information from the joint probability table of two variables
def MutualInformation(jP):
  mi=0.0
# Coursework 2 task 1 should be inserted here
  #print jP
  
  for j in range(jP.shape[1]):
    for i in range(jP.shape[0]):
      p_col= sum(jP[:,j]) 
      #print p_col
      p_row= sum(jP[i])
     # print p_row
      if (jP[i,j] == 0 or (p_col*p_row) == 0):
	mi += 0.0
      else:
	mi +=  jP[i,j]*log((jP[i,j]/(p_col*p_row)),2)
  #for i in range(jP.shape[1]):
   #  p(a) = sum(jP[:,i])
  
  #for j in range(jp.shape[0]):
   #  p(b)= sum(jP[j])

  #print mi

# end of coursework 2 task 1
  return mi
  
  
  
# construct a dependency matrix for all the variables
def DependencyMatrix(theData, noVariables, noStates):
  MIMatrix = zeros((noVariables,noVariables))
# Coursework 2 task 2 should be inserted here
  for j in range(noVariables):
      for i in range(noVariables):
	if(i==j) :
	    MIMatrix[i,j] = 0.0
	else:
	  jpt= JPT(theData, i, j, noStates)
	  MIMatrix[i,j]= MutualInformation(jpt)

# end of coursework 2 task 2
  return MIMatrix
  
  

def DependencyList(depMatrix):
  depList=[]
# Coursework 2 task 3 should be inserted here
  for i in range(depMatrix.shape[0]):
    for j in range(i,depMatrix.shape[1]):
      depList.append([depMatrix[i,j],i,j])
   
  depList.sort(key = lambda value:value [0], reverse=True)

  #print depList
# end of coursework 2 task 3
  return array(depList)  
  
  
#import sys
  
  #
# Functions implementing the spanning tree algorithm
# Coursework 2 task 4

#sys.setrecursionlimit(1000000000)

def makeLoop(doublet, spanningTree):
  #print "Got here ", doublet
  tree_copy = list(spanningTree)
  start_value = doublet[0]
  end_value = doublet[1]
 # print start_value
 # print end_value
 # print "adding ", doublet
 # print end_value
#  print tree_copy
  return recursiveLoopSearch(start_value, end_value, tree_copy)
      

def recursiveLoopSearch(start_value,end_value,tree_copy):
  if(start_value == end_value ):
    #print "true first"
    return True
  
  #print tree_copy
 # print start_value
  for i in tree_copy:
  #  print i
    #if(end_value==7):
   #   print start_value
  # for j in range(0,2):
     
     # if(end_value==7):
	#print "start val", start_value
	#print "j  " , 
	
   # print"looking at " , i
    if (i[0]== start_value or i[1] == start_value):
      if(i[0] == start_value):
	new_start_value = i[1]
      else:
	new_start_value = i[0]
    
      #print new_start_value
     # if (end_value == 7):
	#print new_start_value

	  #new_start_value = i[1-j]
	  #print new_start_value
	  #print new_start_value
	  #print end_value
      new_tree_copy = list (tree_copy)
      new_tree_copy.remove([i[0],i[1]])
      if(recursiveLoopSearch(new_start_value,end_value, new_tree_copy)==True):
	return True

  return False

  '''
def recursiveTree(newlist, spanningTree,count):
  if(newlist.shape[0] == count):
    return

  #print "call Make Loop "
  
  if (makeLoop(newlist[count], spanningTree)==False):
    spanningTree.append(newlist[count])
  
  count+= count
 # print newlist[count][0]
  recursiveTree(newlist, spanningTree,count)
  '''
 

def SpanningTreeAlgorithm(depList, noVariables):
  spanningTree =[]
  newlist= delete(depList, 0,1).tolist()
  #print "Newliiist"  , newlist
  #count = 0
  for element in newlist:
    if (makeLoop(element, spanningTree)==False):
      spanningTree.append(element)
  
  
  
  
  #recursiveTree(newlist, spanningTree, count)
  

  
  
  return array(spanningTree)


  
  
#
# End of coursework 2
#
  
  
#
# main program part for Coursework 2
#

noVariables, noRoots, noStates, noDataPoints, datain = ReadFile("HepatitisC.txt")
theData = array(datain)
AppendString("results.txt","Coursework Two Results by Pierre Eugene Valassakis (pev115, 00644379)")
AppendString("results.txt","") #blank line
AppendString("results.txt","The dependency matrix for the HepatitisC data is")



miMatrix = DependencyMatrix(theData, noVariables, noStates)
AppendArray("results.txt", miMatrix)


deplist = DependencyList(miMatrix)
AppendArray("results.txt",deplist)



tree = SpanningTreeAlgorithm(deplist, noVariables)
#print tree
