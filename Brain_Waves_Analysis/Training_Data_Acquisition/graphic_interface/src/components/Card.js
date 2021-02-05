import React from 'react';

import "./card.css";

class Card extends React.Component {

	constructor(props) {
		super(props);
		this.classNames = "card " + this.props.className;
	}

	render() {
		return (
			<div className={this.classNames}>
				{this.props.children}
			</div>
		);
	}
}

export default Card;