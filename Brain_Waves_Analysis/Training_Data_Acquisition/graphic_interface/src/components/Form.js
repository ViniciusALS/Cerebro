/*
	TODO:
		- Select directory
		- find serial ports connected
		- uplift form data
		- page router
		- dinamic pin selection
*/


import React from 'react';

import "./form.css";

import Card from "./Card.js";

class Form extends React.Component {

	render() {
		return (
			<Card className="form">
				<h2>Save to:</h2>
				<h2>Port:</h2>
				<h2>Session Duration</h2>
				<h2>Pin Connection:</h2>
				<h2>START</h2>
			</Card>
		);
	}
}

export default Form;