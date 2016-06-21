#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Coursework in Python 
from IDAPICourseworkLibrary import *
from numpy import *
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
	
	if N_p > 0 :
	  cPT[j,i] = float(N_candp)/float(N_p)  
	else:
	  1.0/float(noStates[varC])
	  
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
    # Get the conditional probability : P(A|B) = P(A&B)/P(B) .
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
#if the sum is 0, return the distribution 
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




#
# Coursework 2 begins here
#

from math import *

# Calculate the mutual information from the joint probability table of two variables
def MutualInformation(jP):
  mi=0.0
# Coursework 2 task 1 should be inserted here
#Calculate the mutual information : Dep(A,B) = S_AxB P(ai&bj)*log_2((Pai&bj)/(P(ai)P(bj)))
#here P(ai) = p_row , P(bj) = p_col , P(ai&bj) = jP[i,j]. We get:
  for j in range(jP.shape[1]):
    for i in range(jP.shape[0]):
      p_col= sum(jP[:,j]) 
      p_row= sum(jP[i])
      if (jP[i,j] == 0 or (p_col*p_row) == 0):
	mi += 0.0
      else:
	mi +=  jP[i,j]*log((jP[i,j]/(p_col*p_row)),2)
# end of coursework 2 task 1	
  return mi
  
  
  
  

 

# construct a dependency matrix for all the variables
def DependencyMatrix(theData, noVariables, noStates):
  MIMatrix = zeros((noVariables,noVariables))
# Coursework 2 task 2 should be inserted here
#Each element of the dependencyMatrix is the Mutual Information for the
#a possible combination of the vartiables in the data
  for j in range(noVariables):
      for i in range(noVariables):
	if(i==j) :
	    MIMatrix[i,j] = 0.0
	else:
	  #calculate the joint probability table
	  jpt= JPT(theData, i, j, noStates)
	  #extract the mutual information from the joint probabilities
	  MIMatrix[i,j]= MutualInformation(jpt)

# end of coursework 2 task 2
  return MIMatrix




 
def DependencyList(depMatrix):
  depList=[]
# Coursework 2 task 3 should be inserted here
#extract the depedency list from the mutual information matrix: Only consider
#the upper half of the dependency matrix because as it is symmetric
  for i in range(depMatrix.shape[0]):
    for j in range(i,depMatrix.shape[1]):
      depList.append([depMatrix[i,j],i,j])
  #sort the dependency list in order of depedencies
  depList.sort(key = lambda value:value [0], reverse=True)

# end of coursework 2 task 3
  return array(depList)  
  
  
  

# Functions implementing the spanning tree algorithm
# Coursework 2 task 4

#function that checks whether there is a loop that is formed by adding the 
#doublet to the spanningTree. If it does, returns true, else false
def makeLoop(doublet, spanningTree):
  #make a copy of the spanningTree not to modify its values by the test
  tree_copy = list(spanningTree)
  #extract the two values of the doublet
  start_value = doublet[0]
  end_value = doublet[1]
  #check recursively for a loop
  return recursiveLoopSearch(start_value, end_value, tree_copy)
      
#function that recursively looks for a loop
def recursiveLoopSearch(start_value,end_value,tree_copy):
  #if a loop is found, return TRUE
  if(start_value == end_value ):
    return True

  for i in tree_copy:
    #if the start value is found in the spannigTree, set its connected pair
    #to the new start value
    if (i[0]== start_value or i[1] == start_value):
      if(i[0] == start_value):
	new_start_value = i[1]
      else:
	new_start_value = i[0]
    #make a copy of the tree and delete the doublet found
      new_tree_copy = list (tree_copy)
      new_tree_copy.remove([i[0],i[1]])
      #call the function recursively, and if a loop is found cascade the true
      #result
      if(recursiveLoopSearch(new_start_value,end_value, new_tree_copy)==True):
	return True
  #if no loop is found at the end of the recursion, propagate the false result
  return False

#Function that returns the spanning tree of the variables in the dataset,
#given the dependency list
def SpanningTreeAlgorithm(depList, noVariables):
  spanningTree =[]
  #delete the first column of the dependency list (as they are already ordered)
  newlist= delete(depList, 0,1).tolist()

  #for each element down the dependency list, try to establish a connection
  #only establish the connection if it does not result in a loop
  for element in newlist:
    if (makeLoop(element, spanningTree)==False):
      spanningTree.append(element)

  return array(spanningTree)



#
# End of coursework 2
#
  




#
# Coursework 3 begins here
#






#                                  QUESTION 3.1

# Function to compute a CPT with multiple parents from he data set
# it is assumed that the states are designated by consecutive integers starting with 0
def CPT_2(theData, child, parent1, parent2, noStates):
  cPT = zeros([noStates[child],noStates[parent1],noStates[parent2]], float )
  
# Coursework 3 task 1 should be inserted here
# For each of the states of the child and the two parents - (i , j, k), respectively-
  for i in range(noStates[child]):
    for j in range(noStates[parent1]):
      for k in range(noStates[parent2]): 
	
	#Compute te number of occurances that the two parents are states j and k
	N_p1p2 = list(theData[theData[:,parent1]==j][:,parent2]).count(k)
	#and the number of occurences where the child and the parents 
	#are in states (i,j,k)
	temp = array(theData[theData[:,parent1]==j])
	N_p1p2c = list(temp[temp[:,parent2]==k][:,child]).count(i)
	
	#if there is no datapoint where the parents are in the states j and k
	#give equal probability to all the child states
	#else get the conditional probability P(child=i|parent1=j, parent2=k) = N_p1p2c/N_p1p2
	if(N_p1p2==0):
	    cPT[i,j,k] = float(1)/float(noStates[child])
	else:
	  cPT[i,j,k] = float(N_p1p2c)/float(N_p1p2)

# End of Coursework 3 task 1           
  return cPT




#                           QUESTION 3.2

# Definition of a Bayesian Network
def ExampleBayesianNetwork(theData, noStates):
    arcList = [[0],[1],[2,0],[3,2,1],[4,3],[5,3]]
    cpt0 = Prior(theData, 0, noStates)
    cpt1 = Prior(theData, 1, noStates)
    cpt2 = CPT(theData, 2, 0, noStates)
    cpt3 = CPT_2(theData, 3, 2, 1, noStates)
    cpt4 = CPT(theData, 4, 3, noStates)
    cpt5 = CPT(theData, 5, 3, noStates)
    cptList = [cpt0, cpt1, cpt2, cpt3, cpt4, cpt5]
    return arcList, cptList
# Coursework 3 task 2 begins here

#Define the HepatitisC Bayesian Network
def HepatitisCNetwork(theData, noStates):
  arcList = [[0],[1],[2,0],[7,0,1],[6,1],[4,1],[8,7],[5,4],[3,4]]
  cpt0 = Prior(theData,0, noStates)
  cpt1 = Prior(theData,1,noStates)
  cpt2 = CPT(theData,2,0,noStates)
  cpt3 = CPT(theData,3,4,noStates)
  cpt4 = CPT(theData,4,1,noStates)
  cpt5 = CPT(theData,5,4,noStates)
  cpt6 = CPT(theData,6,1,noStates)
  cpt7 = CPT_2(theData,7,0,1,noStates)
  cpt8 = CPT(theData,8,7,noStates)
  cptList = [ cpt0, cpt1,cpt2,cpt3,cpt4,cpt5,cpt6,cpt7,cpt8]
  return arcList, cptList

# end of coursework 3 task 2
#





#                            QUESTION 3.3

# Function to calculate the MDL size of a Bayesian Network
def MDLSize(arcList, cptList, noDataPoints, noStates):
  mdlSize = 0.0
# Coursework 3 task 3 begins here

  log2N = log(noDataPoints,2)
  
  #compute the minimum number of parameters
  #required to represent all the probabilities
  #iterate through all the probability tables, and add the number of parameters
  #required to represent each one
  for i in cptList:
    param_nb = 1.0
    for j in range(len(i.shape)):
      if(j== 0):
      #For the first dimention of each table we need n-1 parameters to represent
      # it where n is its length
	param_nb *= i.shape[j] -1  
      else:
	param_nb *= i.shape[j]
	
    mdlSize += param_nb
    
  #get the model size = min_number_of_parameters*log2N/2  
  mdlSize = float(mdlSize * log2N )/2.0

# Coursework 3 task 3 ends here 
  return mdlSize 




#                          QUESTION 3.4

# Function to calculate the joint probability of a single data point in a Network
def JointProbability(dataPoint, arcList, cptList):
  jP = 1.0
# Coursework 3 task 4 begins here
  #Get the value of jP by multiplying the conditional or prior probabilities
  #of each node in the network together.
  for arc in arcList:
    node = arc[0]
    node_value = dataPoint[node]
  #If the node considered is a root, multiply jP by the prior probability
  #that this root is at the given state
    if(len(arc)==1):
      jP *= cptList[node][node_value]
    #If a node has one parent, multiply jP by the conditional probability
    #of its value given its parent
    elif(len(arc)==2):
      parent = arc[1]
      parent_value = dataPoint[parent]
      jP*= cptList[node][node_value][parent_value]
    #If a node has two parents, multiply jP by the conditional probability
    #of its value given its two parents
    else:
      parent1= arc[1]
      parent2= arc[2]
      parent1_value = dataPoint[parent1]
      parent2_value = dataPoint[parent2]
      jP *= cptList[node][node_value][parent1_value][parent2_value]

# Coursework 3 task 4 ends here 
  return jP








#                        QUESTION 3.5
# Function to calculate the MDLAccuracy from a data set
#
# We want to find the log likelyhood of the model:
# Log_likelyhood = log_2(Product(P(Bn),data)), where P(Bn) is the 
# join probabity of each data point
# Hence: Log_likelyhood = Sum(log_2(P(Bn)))
#
def MDLAccuracy(theData, arcList, cptList):
  mdlAccuracy=0
# Coursework 3 task 5 begins here
  #for each datapoint calculate the log of its join probability and add it
  #to the mdlAccuracy
  for i in range(theData.shape[0]):
    if(JointProbability(theData[i],arcList,cptList) != 0): 
      mdlAccuracy += log(JointProbability(theData[i],arcList,cptList),2)

# Coursework 3 task 5 ends here 
  return mdlAccuracy










#                           QUESTION 3.6                
#Function that finds the best scoring network that can be obtained by 
#deleting one arc from the initial tree
def BestScoringTree(theData, arcList, cptList, noDataPoints, noStates):

  #Keep track of the actual best score and the tree that produced this best score
  bestScore = MDLSize(arcList, cptList, noDataPoints, noStates) - MDLAccuracy(theData, arcList, cptList)
  bestTree  = list(arcList)
  
  #Delete each arc in the tree one by one and recompute the score. Compare with the 
  #current best score and update the values of bestTree and bestScore if necessary
  for arc in arcList:
    
    #Single parent case:
    if (len(arc) ==2):
      #Create copies of arcList and cptList
      arcListCopy = list(arcList)
      cptListCopy = list(cptList)
      
      #Remove the arc considered
      arcListCopy.remove(arc)
      arc = [arc[0]]
      arcListCopy.append(arc)
      
      #Update the CPTlist for the new tree considered
      cptListCopy[arc[0]] = Prior(theData, arc[0], noStates)

      #Calculate the score of the new tree
      Score = MDLSize(arcListCopy, cptListCopy, noDataPoints, noStates) - MDLAccuracy(theData, arcListCopy, cptListCopy)
      
      #Update bestScore and bestTree if necessary
      if(Score<bestScore):
	bestScore = Score
	bestTree = arcListCopy
	  
	  
    #Two parents case:
    elif(len(arc)==3):
      #Consider each arc connecting the node to its parents
      for i in range(1,3):
	#Create copies of arcList and cptList
	arcListCopy = list(arcList)
	cptListCopy = list(cptList)
	
	#remove the arc considered
	arcListCopy.remove(arc)
	new_arc =[arc[0],arc[i]]
	arcListCopy.append(new_arc)

	#Update the CPTList for the new tree considered
	cptListCopy[new_arc[0]]= CPT(theData,new_arc[0],new_arc[1],noStates)
	
	#Calculate the score of the new tree
	Score = MDLSize(arcListCopy, cptListCopy, noDataPoints, noStates) - MDLAccuracy(theData, arcListCopy, cptListCopy)
	
	#Update the bestScore and bestTree if necessary
	if(Score < bestScore):
	  bestScore = Score
	  bestTree = arcListCopy

  return bestTree , bestScore






#
# Coursework 4 begins here
#


def Mean(theData):
  realData = theData.astype(float)
  noVariables=theData.shape[1] 
  mean = []
  # Coursework 4 task 1 begins here
  noDataPoints = theData.shape[0]
  #Sum over the columns and divide by the number of datapoints to get the mean 
  #value for each column
  for i in range(noVariables):
    mean.append(float(sum(theData[:,i]))/float(noDataPoints))

 # Coursework 4 task 1 ends here
  return array(mean)





def Covariance(theData):
  realData = theData.astype(float)
  noVariables=theData.shape[1] 
  covar = zeros((noVariables, noVariables), float)
  # Coursework 4 task 2 begins here
  noDataPoints = realData.shape[0]
  #subtact the column's mean from each of the datapoints
  mean = Mean(realData)
  realData -= mean

  #Find the covariance by matrix multiplication and dividing
  #by the number of data points -1
  covar = dot( transpose(realData), realData)
  covar= covar/(noDataPoints-1)
  
  # Coursework 4 task 2 ends here
  return covar  
  
  
  
  
  
def CreateEigenfaceFiles(theBasis):
  # Coursework 4 task 3 begins here
  #Save the eigenfaces present in theBasis matrix in jpg format
  for i in range(theBasis.shape[0]):
    SaveEigenface(theBasis[i],"PrincipalComponent"+str(i)+".jpg")
    
  # Coursework 4 task 3 ends here






def ProjectFace(theBasis, theMean, theFaceImage):
    magnitudes = []
    # Coursework 4 task 4 begins here
    #get the mean in data form
    mean = ReadOneImage(theMean)
    #get the face in data form
    theface = ReadOneImage(theFaceImage)
    #center the image buy subtacting the mean
    centered_image = array(theface) - array(mean)

    #Get the magnitudes by projecting the centered_image into the 
    #given basis
    magnitudes = dot(centered_image,theBasis.T)
 
    # Coursework 4 task 4 ends here
    return array(magnitudes)







def CreatePartialReconstructions(aBasis, aMean, componentMags):
  #get the mean
  mean = ReadOneImage(aMean)
  # Reconstruct the image: Start from the mean and
  #create and save successive images by adding to the mean each of the components
  #in the basis
  for i in range(componentMags.shape[0]):
    mean += aBasis[i]*componentMags[i]
    SaveEigenface(mean,"ReconstructedComponent"+str(i)+".jpg")

    # Coursework 4 task 5 ends here




def PrincipalComponents(theData):
  orthoPhi = []
  # Coursework 4 task 3 begins here
  # The first part is almost identical to the above Covariance function, but because the
  # data has so many variables you need to use the Kohonen Lowe method described in lecture 15
  # The output should be a list of the principal components normalised and sorted in descending 
  # order of their eignevalues magnitudes

  #the Data is made of the images in data form, with one image per row
  mean = Mean(theData)
   
  #center the data by subtacting the mean 
  centered_data = theData - mean
  
  #get the intermediate matrix of the Kohonen Lowe method and
  #find its eigenvalues and eigenvectors
  transform_matrix = dot(centered_data,transpose(centered_data))

  eigenvalues, eigenvectors = linalg.eig(transform_matrix)
  
  #find the dot product with the transpose of centered_data to get the eigenvectors
  # of the covariance matrix of our data
  eigenvectors_final = dot(transpose(centered_data), eigenvectors)

  #Sort the matrix to get the eigenvectors sorted by eigenvalue 
  #(eigenvector with the biggest eigenvalue goes first)
  #In our example it is not essencial as we only have 6 images and we are going to use
  #all of them for our basis but in the case we have more images we will want to chose the
  #ones with the highest eigenvalues
  sort_order = eigenvalues.argsort()[::-1]
  eigenvalues = eigenvalues[sort_order]
  eigenvectors_final = eigenvectors_final[:,sort_order]
  
  #Traspose the matrix to get the eigenvectors along the rows
  eigenvectors_final = transpose(eigenvectors_final)
  
  #normalise the eigenvectors
  for i in range(eigenvectors_final.shape[0]):
    eigenvectors_final[i] = eigenvectors_final[i]/linalg.norm(eigenvectors_final[i])
    

  orthoPhi = eigenvectors_final
  # Coursework 4 task 6 ends here
  return array(orthoPhi)










	
# main program part for Coursework 4
#

#Header
noVariables, noRoots, noStates, noDataPoints, datain = ReadFile("HepatitisC.txt")
theData = array(datain)
AppendString("IDAPIResults04.txt","") #blank line
AppendString("IDAPIResults04.txt","Coursework Four results by Pierre Eugene Valassakis (pev115, 00644379)")
AppendString("IDAPIResults04.txt","") #blank line


AppendString("IDAPIResults04.txt","2. The mean vector for the HepatitisC Dataset is:")
HepatitisCMean = Mean(theData) 
AppendList("IDAPIResults04.txt",HepatitisCMean)

AppendString("IDAPIResults04.txt","3. The covariance matrix for the HepatitisC dataset is:")
HepatitisCCovariance = Covariance(theData)
AppendArray("IDAPIResults04.txt",HepatitisCCovariance)


#The two following sections recreate the image c.img from the meanImage and the 
#using pca. Because both create a set of images with the same names, if they are run at the same time
#one set is going to override the other.

#Therefore the flag using_q_6 is created. Set to true to reproduce the images using the Kohonen Lowe
#method in question 4.6

using_q_6 = True


if(using_q_6 == False):
  # # # # # # # Using the given Basis in the PrincipalComponents.txt # # # # # # # # # # 

  #Read the given basis in the PrincipalComponents.txt file
  theGivenBasis = ReadEigenfaceBasis()

  #Create image files from the given basis
  CreateEigenfaceFiles(theGivenBasis)

  #Get the component magnitudes in the given basis 
  componentMagnitudes = ProjectFace(theGivenBasis,  "MeanImage.jpg","c.pgm")
  AppendString("IDAPIResults04.txt","4. The component magnitudes for the image c.pgm in the given principal component basis is:")
  AppendList("IDAPIResults04.txt",componentMagnitudes)

  #Reconstruct the image from the mean image using the given basis
  CreatePartialReconstructions(theGivenBasis, "MeanImage.jpg", componentMagnitudes)

  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
else:
  # # # # # # Using the given images a to f to find the Principal Components # # # # # # 

  #Read the images a to f and put them in Data form in a matrix where each row 
  #corresponds to one image
  read_values= ReadImages()
  theImageData = array(read_values)

  #Find the principalComponent matrix
  principalComponents = PrincipalComponents(theImageData)
  
  #Follow the same steps as before but using the principal component basis found using
  #the images a to f
  CreateEigenfaceFiles(principalComponents)
  principalComponentMagnitudes =  ProjectFace(principalComponents,  "MeanImage.jpg","c.pgm")
  AppendString("IDAPIResults04.txt","The component magnitudes for the image in the basis found from the images is:")
  AppendList("IDAPIResults04.txt",principalComponentMagnitudes)
  CreatePartialReconstructions(principalComponents, "MeanImage.jpg", principalComponentMagnitudes)

  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

